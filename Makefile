# $NetBSD: Makefile,v 1.22 1999/03/03 20:19:05 hubertf Exp $
# FreeBSD Id: Makefile,v 1.35 1997/08/19 07:10:01 fenner Exp
#

.include "mk/bsd.prefs.mk"

.ifdef SPECIFIC_PKGS
SUBDIR+=	${SITE_SPECIFIC_PKGS}
SUBDIR+=	${HOST_SPECIFIC_PKGS}
SUBDIR+=	${GROUP_SPECIFIC_PKGS}
SUBDIR+=	${USER_SPECIFIC_PKGS}
.else
#SUBDIR += ai
SUBDIR += archivers
#SUBDIR += astro
SUBDIR += audio
SUBDIR += benchmarks
SUBDIR += cad
#SUBDIR += chinese
SUBDIR += comms
SUBDIR += converters
SUBDIR += corba
SUBDIR += cross
SUBDIR += databases
SUBDIR += devel
SUBDIR += editors
SUBDIR += emulators
SUBDIR += games
#SUBDIR += german
SUBDIR += graphics
SUBDIR += japanese
#SUBDIR += korean
SUBDIR += lang
SUBDIR += mail
SUBDIR += math
SUBDIR += mbone
SUBDIR += meta-pkgs
SUBDIR += misc
SUBDIR += net
SUBDIR += news
SUBDIR += parallel
SUBDIR += pkgtools
SUBDIR += plan9
SUBDIR += print
#SUBDIR += russian
SUBDIR += security
SUBDIR += shells
SUBDIR += sysutils
SUBDIR += textproc
#SUBDIR += vietnamese
SUBDIR += www
SUBDIR += x11
.endif

PKGSRCTOP=	yes

.include "mk/bsd.pkg.subdir.mk"

index:
	@rm -f ${.CURDIR}/INDEX
	@${MAKE} ${.CURDIR}/INDEX

${.CURDIR}/INDEX:
	@echo -n "Generating INDEX - please wait.."
	@${MAKE} describe ECHO_MSG="echo > /dev/null" > ${.CURDIR}/INDEX
	@echo " Done."

print-index:	${.CURDIR}/INDEX
	@awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\nArch:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9, $$10); }' < ${.CURDIR}/INDEX

search:	${.CURDIR}/INDEX
.if !defined(key)
	@echo "The search target requires a keyword parameter,"
	@echo "e.g.: \"${MAKE} search key=somekeyword\""
.else
	@grep ${key} ${.CURDIR}/INDEX | awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\nArch:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9, $$10); }'
.endif

