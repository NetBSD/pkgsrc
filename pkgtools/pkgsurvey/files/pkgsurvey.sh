#! /bin/sh

${PKG_INFO} | sort | mail -s "`hostname` `${UNAME} -s`-`${UNAME} -p`-`${UNAME} -r`" agc-pkgsurvey@pkgsrc.org

exit 0
