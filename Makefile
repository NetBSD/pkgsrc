# $NetBSD: Makefile,v 1.14 1998/08/12 02:45:27 tv Exp $
# FreeBSD Id: Makefile,v 1.35 1997/08/19 07:10:01 fenner Exp
#

#SUBDIR += ai
SUBDIR += archivers
#SUBDIR += astro
SUBDIR += audio
SUBDIR += benchmarks
SUBDIR += cad
#SUBDIR += chinese
SUBDIR += comms
SUBDIR += converters
SUBDIR += cross
SUBDIR += databases
SUBDIR += devel
SUBDIR += editors
SUBDIR += emulators
SUBDIR += games
#SUBDIR += german
SUBDIR += graphics
#SUBDIR += japanese
#SUBDIR += korean
SUBDIR += lang
SUBDIR += mail
SUBDIR += math
SUBDIR += mbone
SUBDIR += meta-pkgs
SUBDIR += misc
SUBDIR += net
SUBDIR += news
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

PKGSRCTOP=	yes

.include "mk/bsd.pkg.subdir.mk"

index:
	@rm -f ${.CURDIR}/INDEX
	@make ${.CURDIR}/INDEX

${.CURDIR}/INDEX:
	@echo -n "Generating INDEX - please wait.."
	@make describe ECHO_MSG="echo > /dev/null" > ${.CURDIR}/INDEX
	@echo " Done."

print-index:	${.CURDIR}/INDEX
	@awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\nArch:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9, $$10); }' < ${.CURDIR}/INDEX

search:	${.CURDIR}/INDEX
.if !defined(key)
	@echo "The search target requires a keyword parameter,"
	@echo "e.g.: \"make search key=somekeyword\""
.else
	@grep ${key} ${.CURDIR}/INDEX | awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\nArch:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9, $$10); }'
.endif
