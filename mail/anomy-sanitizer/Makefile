# $NetBSD: Makefile,v 1.41 2022/06/28 11:34:16 wiz Exp $
#

DISTNAME=	anomy-sanitizer-1.76
PKGREVISION=	13
CATEGORIES=	mail
MASTER_SITES=	http://mailtools.anomy.net/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mailtools.anomy.net/
COMMENT=	Mail message filter and sanitizer

#DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/anomy
USE_TOOLS+=	perl:run pax

REPLACE_PERL+=			bin/*.pl
CHECK_INTERPRETER_SKIP+=	*.pm

ANOMYLIB=	${PREFIX}/lib/anomy-sanitizer
ANOMYDOC=	${PREFIX}/share/doc/anomy-sanitizer

INSTALLATION_DIRS=	sbin

post-extract:
	chmod -R u+w,go-w,a+r ${WRKSRC}
	cd ${WRKSRC}/bin/Anomy && chmod a-x *.pm */*.pm

do-build:
	set -e; \
	cd ${WRKSRC}; \
	    for i in mailblogger sanitizer simplify; do \
		( \
		    ${ECHO} '#!${SH}'; \
		    ${ECHO} 'ANOMY=${ANOMYLIB}'; \
		    ${ECHO} 'export ANOMY'; \
		    ${ECHO} 'exec $${ANOMY}/bin/'"$$i"'.pl "$$@"'; \
		) > "$$i"; \
	    done; \
	    [ -d contrib/.tmp ] && rmdir contrib/.tmp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sanitizer ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/simplify ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DESTDIR}${ANOMYDOC}
	cd ${WRKSRC} && pax -rw -s',.*\.orig$$,,' -s',^\..*$$,,' \
	    CHANGELOG.sanitizer \
	    CREDITS \
	    README.sanitizer \
	    UNICODE.TXT \
	    contrib \
	    sanitizer.html \
	    ${DESTDIR}${ANOMYDOC}
	${INSTALL_DATA_DIR} ${DESTDIR}${ANOMYLIB}
	${INSTALL_DATA_DIR} ${DESTDIR}${ANOMYLIB}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mailblogger.pl ${DESTDIR}${ANOMYLIB}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sanitizer.pl ${DESTDIR}${ANOMYLIB}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/simplify.pl ${DESTDIR}${ANOMYLIB}/bin
	cd ${WRKSRC}/bin && pax -rw -s',.*\.orig$$,,' Anomy \
	    ${DESTDIR}${ANOMYLIB}/bin

.include "../../mk/bsd.pkg.mk"
