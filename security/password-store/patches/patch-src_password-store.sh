$NetBSD: patch-src_password-store.sh,v 1.1 2015/01/02 12:52:16 imil Exp $

Remove non portable mkdir parameter

--- src/password-store.sh.orig	2014-07-01 08:42:26.000000000 +0000
+++ src/password-store.sh
@@ -291,7 +291,7 @@ cmd_init() {
 		fi
 		rmdir -p "${gpg_id%/*}" 2>/dev/null
 	else
-		mkdir -v -p "$PREFIX/$id_path"
+		mkdir -p "$PREFIX/$id_path"
 		printf "%s\n" "$@" > "$gpg_id"
 		local id_print="$(printf "%s, " "$@")"
 		echo "Password store initialized for ${id_print%, }"
@@ -382,7 +382,7 @@ cmd_insert() {
 
 	[[ $force -eq 0 && -e $passfile ]] && yesno "An entry already exists for $path. Overwrite it?"
 
-	mkdir -p -v "$PREFIX/$(dirname "$path")"
+	mkdir -p "$PREFIX/$(dirname "$path")"
 	set_gpg_recipients "$(dirname "$path")"
 
 	if [[ $multiline -eq 1 ]]; then
@@ -416,7 +416,7 @@ cmd_edit() {
 
 	local path="$1"
 	check_sneaky_paths "$path"
-	mkdir -p -v "$PREFIX/$(dirname "$path")"
+	mkdir -p "$PREFIX/$(dirname "$path")"
 	set_gpg_recipients "$(dirname "$path")"
 	local passfile="$PREFIX/$path.gpg"
 
@@ -455,7 +455,7 @@ cmd_generate() {
 	local length="$2"
 	check_sneaky_paths "$path"
 	[[ ! $length =~ ^[0-9]+$ ]] && die "Error: pass-length \"$length\" must be a number."
-	mkdir -p -v "$PREFIX/$(dirname "$path")"
+	mkdir -p "$PREFIX/$(dirname "$path")"
 	set_gpg_recipients "$(dirname "$path")"
 	local passfile="$PREFIX/$path.gpg"
 
@@ -538,7 +538,7 @@ cmd_copy_move() {
 		[[ ! -f $old_path ]] && die "Error: $1 is not in the password store."
 	fi
 
-	mkdir -p -v "${new_path%/*}"
+	mkdir -p "${new_path%/*}"
 	[[ -d $old_path || -d $new_path || $new_path =~ /$ ]] || new_path="${new_path}.gpg"
 
 	local interactive="-i"
