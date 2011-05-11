############################################################
# Written by Aleksey Cheusov <vle@gmx.net>
# Public Domain

############################################################
# dewey functions

BEGIN {
	__dewey_maxf = 9 # 8(YYYYMMDD) + 1
	for (i=0; i < 26; ++i){
		# I don't know anything about EBCDIC :-P :-)
		__dewey_char2dotver [sprintf("%c", 65 + i)] = "." i+1 "."
	}
}

function __dewey_chars (n, c,            s){
	s = ""

	while (n-- > 0){
		s = s c
	}

	return s
}

function __remove_leading0 (ver,     tmp){
	if (match(ver, /[0-9]+/)){
		tmp = substr(ver, RSTART, RLENGTH)
		sub(/^0+/, "", tmp)
		if (tmp == ""){
			tmp = 0
		}
		return \
		   substr(ver, 1, RSTART-1) \
		   tmp \
		   __remove_leading0(substr(ver, RSTART+RLENGTH))
	}else{
		return ver
	}
}

function __dewey2str (ver,        left,right,sym,num,last){
	ver = __remove_leading0(toupper(ver))

	gsub(/ALPHA/, "\072", ver) # A
	gsub(/BETA/, "\073", ver)  # B
	gsub(/RC/, "\074", ver)    # C
	gsub(/PRE/, "\074", ver)   # C
	gsub(/NB/, "\076", ver)    # Y
	gsub(/PL/, ".", ver)       # .
	gsub(/_/, ".", ver)        # .

	if (match(ver, /([.]0+)+$/)){
		# 1.2.0.0 -> 1.2
		ver = substr(ver, 1, RSTART-1)
	}else if (match(ver, /([.]0+)+(\072|\073|\074|\076)/)){
		# 1.2.0.0nb1 -> 1.2nb1
		ver = substr(ver, 1, RSTART-1) substr(ver, RSTART+RLENGTH-1)
	}

	ver = "." ver

	while (match(ver, /[QWERTYUIOPASDFGHJKLZXCVBNM]/)){
		last = substr(ver, RSTART, 1)
		ver = substr(ver, 1, RSTART-1) \
		      __dewey_char2dotver [last] \
		      substr(ver, RSTART+1)
	}

	gsub(/[.][.]+/, ".", ver)
	sub(/[.]$/, "", ver)
	sub(/[.]\076/, "\076", ver)

	gsub(/[.]/, "\100" __dewey_chars(__dewey_maxf, " ") ".", ver) # Z

	while (match(ver, /[\072\073\074\076.][0-9]+/)){
		left  = substr(ver, 1, RSTART-1)
		sym   = substr(ver, RSTART, 1)
		num   = substr(ver, RSTART+1, RLENGTH-1)
		right = substr(ver, RSTART+RLENGTH)

		num = sprintf("%" __dewey_maxf "s", num)

		if (sym == ".")
			ver = left "\100" num right # Z
		else
			ver = left sym num right
	}

	return substr(ver, __dewey_maxf + 2) "\075" # X
}

function dewey_cmp (ver1, ver2,             s1,s2){
	if (ver1 == ver2){
		return "="
	}

	s1 = __dewey2str(ver1)
	s2 = __dewey2str(ver2)

	if (s1 < s2)
		return "<"
	else if (s1 > s2)
		return ">"
	else
		return "="
}

function dewey_test (ver1, ver2, op,                 tmp){
	tmp = dewey_cmp(ver1, ver2)

	if (tmp ~ /^==?$/ && op ~ /^(==|=|<=|>=)$/){
		return 1
	}else if (tmp == "<" && op ~ /^(<=?|!=)$/){
		return 1
	}else if (tmp == ">" && op ~ /^(>=?|!=)$/){
		return 1
	}

	return 0
}
