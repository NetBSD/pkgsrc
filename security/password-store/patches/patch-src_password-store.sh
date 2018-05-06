$NetBSD: patch-src_password-store.sh,v 1.2 2018/05/06 11:56:58 leot Exp $

Avoid non portable mkdir(1) `-v' parameter.

--- src/password-store.sh.orig	2017-04-13 10:11:14.000000000 +0000
+++ src/password-store.sh
@@ -323,7 +323,7 @@ cmd_init() {
 		fi
 		rmdir -p "${gpg_id%/*}" 2>/dev/null
 	else
-		mkdir -v -p "$PREFIX/$id_path"
+		mkdir -p "$PREFIX/$id_path"
 		printf "%s\n" "$@" > "$gpg_id"
 		local id_print="$(printf "%s, " "$@")"
 		echo "Password store initialized for ${id_print%, }${id_path:+ ($id_path)}"
@@ -430,7 +430,7 @@ cmd_insert() {
 
 	[[ $force -eq 0 && -e $passfile ]] && yesno "An entry already exists for $path. Overwrite it?"
 
-	mkdir -p -v "$PREFIX/$(dirname "$path")"
+	mkdir -p "$PREFIX/$(dirname "$path")"
 	set_gpg_recipients "$(dirname "$path")"
 
 	if [[ $multiline -eq 1 ]]; then
@@ -464,7 +464,7 @@ cmd_edit() {
 
 	local path="${1%/}"
 	check_sneaky_paths "$path"
-	mkdir -p -v "$PREFIX/$(dirname "$path")"
+	mkdir -p "$PREFIX/$(dirname "$path")"
 	set_gpg_recipients "$(dirname "$path")"
 	local passfile="$PREFIX/$path.gpg"
 	set_git "$passfile"
@@ -506,7 +506,7 @@ cmd_generate() {
 	local length="${2:-$GENERATED_LENGTH}"
 	check_sneaky_paths "$path"
 	[[ ! $length =~ ^[0-9]+$ ]] && die "Error: pass-length \"$length\" must be a number."
-	mkdir -p -v "$PREFIX/$(dirname "$path")"
+	mkdir -p "$PREFIX/$(dirname "$path")"
 	set_gpg_recipients "$(dirname "$path")"
 	local passfile="$PREFIX/$path.gpg"
 	set_git "$passfile"
@@ -595,7 +595,7 @@ cmd_copy_move() {
 	echo "$old_path"
 	[[ -e $old_path ]] || die "Error: $1 is not in the password store."
 
-	mkdir -p -v "${new_path%/*}"
+	mkdir -p "${new_path%/*}"
 	[[ -d $old_path || -d $new_path || $new_path == */ ]] || new_path="${new_path}.gpg"
 
 	local interactive="-i"
