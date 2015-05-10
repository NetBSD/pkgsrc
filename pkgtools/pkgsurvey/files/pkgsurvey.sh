#! /bin/sh

${PKG_INFO} -e '*' | while read pkg; do
	path=`${PKG_INFO} -Q PKGPATH "$pkg"`
	automatic=`${PKG_INFO} -Q automatic "$pkg"`
	if [ -z "$automatic" ]; then
		automatic=no
	fi
	echo "$path $pkg $automatic"
done | sort | mail -s "`hostname` `${UNAME} -s`-`${UNAME} -p`-`${UNAME} -r`" pkgsurvey1.0@pkgsrc.org

exit 0
