# $NetBSD: Makefile,v 1.18 2001/01/29 11:34:31 wiz Exp $
# FreeBSD Id: Makefile,v 1.24 1997/05/14 14:40:34 ache Exp
#

DISTNAME=	procmail-3.15
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.procmail.org/pub/procmail/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.procmail.org/

INSTALL_TARGET=	install-suid install.man
MAKE_ENV=	SHELL=/bin/sh

post-patch:
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h-orig
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' < ${WRKSRC}/config.h-orig \
		> ${WRKSRC}/config.h
	${MV} ${WRKSRC}/man/procmail.man ${WRKSRC}/man/procmail.man-orig
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|g' \
		< ${WRKSRC}/man/procmail.man-orig \
		> ${WRKSRC}/man/procmail.man

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
do-install:
	cd ${WRKSRC}/new;						\
	for f in procmail formail lockfile; do				\
		${INSTALL_PROGRAM} $$f ${LOCALBASE}/bin/$$f;		\
	done;								\
	${INSTALL_SCRIPT} mailstat ${LOCALBASE}/bin/mailstat;		\
	for f in procmail.1 formail.1 lockfile.1; do			\
		${INSTALL_MAN} $$f ${LOCALBASE}/man/man1/$$f;		\
	done;								\
	for f in procmailex.5 procmailrc.5 procmailsc.5; do		\
		${INSTALL_MAN} $$f ${LOCALBASE}/man/man5/$$f;		\
	done
	${SH} ${WRKSRC}/suid.sh
.endif

.include "../../mk/bsd.pkg.mk"
