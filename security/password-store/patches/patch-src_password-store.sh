$NetBSD: patch-src_password-store.sh,v 1.3 2018/06/14 16:08:39 leot Exp $

Avoid non portable mkdir(1) `-v' parameter.

--- src/password-store.sh.orig	2018-06-14 14:58:28.000000000 +0000
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
@@ -432,7 +432,7 @@ cmd_insert() {
 
 	[[ $force -eq 0 && -e $passfile ]] && yesno "An entry already exists for $path. Overwrite it?"
 
-	mkdir -p -v "$PREFIX/$(dirname -- "$path")"
+	mkdir -p "$PREFIX/$(dirname -- "$path")"
 	set_gpg_recipients "$(dirname -- "$path")"
 
 	if [[ $multiline -eq 1 ]]; then
@@ -466,7 +466,7 @@ cmd_edit() {
 
 	local path="${1%/}"
 	check_sneaky_paths "$path"
-	mkdir -p -v "$PREFIX/$(dirname -- "$path")"
+	mkdir -p "$PREFIX/$(dirname -- "$path")"
 	set_gpg_recipients "$(dirname -- "$path")"
 	local passfile="$PREFIX/$path.gpg"
 	set_git "$passfile"
@@ -509,7 +509,7 @@ cmd_generate() {
 	check_sneaky_paths "$path"
 	[[ $length =~ ^[0-9]+$ ]] || die "Error: pass-length \"$length\" must be a number."
 	[[ $length -gt 0 ]] || die "Error: pass-length must be greater than zero."
-	mkdir -p -v "$PREFIX/$(dirname -- "$path")"
+	mkdir -p "$PREFIX/$(dirname -- "$path")"
 	set_gpg_recipients "$(dirname -- "$path")"
 	local passfile="$PREFIX/$path.gpg"
 	set_git "$passfile"
@@ -598,7 +598,7 @@ cmd_copy_move() {
 	echo "$old_path"
 	[[ -e $old_path ]] || die "Error: $1 is not in the password store."
 
-	mkdir -p -v "${new_path%/*}"
+	mkdir -p "${new_path%/*}"
 	[[ -d $old_path || -d $new_path || $new_path == */ ]] || new_path="${new_path}.gpg"
 
 	local interactive="-i"
