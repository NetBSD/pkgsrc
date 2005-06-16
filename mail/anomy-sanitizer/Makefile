# $NetBSD: Makefile,v 1.17 2005/06/16 06:58:02 jlam Exp $
#

DISTNAME=	anomy-sanitizer-1.69
CATEGORIES=	mail
MASTER_SITES=	http://mailtools.anomy.net/dist/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://mailtools.anomy.net/
COMMENT=	Mail message filter and sanitizer

DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/anomy
NO_CONFIGURE=	# defined
USE_PERL5=	# defined

ANOMYLIB=	${PREFIX}/lib/anomy-sanitizer
ANOMYDOC=	${PREFIX}/share/doc/anomy-sanitizer

INSTALLATION_DIRS=	sbin

do-build:
	cd ${WRKSRC} && ( \
	    for i in sanitizer simplify; do \
		( \
		    cd bin && ${MV} -f $$i.pl $$i.pl.orig && \
		    ${SED} 's;/usr/bin/perl;${PERL5};' $$i.pl.orig > $$i.pl; \
		); \
		( \
		    ${ECHO} '#!${SH}'; \
		    ${ECHO} 'export ANOMY'; \
		    ${ECHO} 'ANOMY=${ANOMYLIB}'; \
		    ${ECHO} 'exec $${ANOMY}/bin/'$$i'.pl "$$@"'; \
		) > $$i; \
	    done; \
	)

do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/sanitizer ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/simplify ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${ANOMYDOC}
	cd ${WRKSRC} && ${PAX} -rw -s',.*\.orig$$,,' -s',^\..*$$,,' \
	    CHANGELOG.sanitizer \
	    CREDITS \
	    README.sanitizer \
	    UNICODE.TXT \
	    contrib \
	    sanitizer.html \
	    ${ANOMYDOC}
	${CHMOD} -R u=rw,go=r ${ANOMYDOC}
	${CHMOD} -R a+X ${ANOMYDOC}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${ANOMYDOC}
	${INSTALL_DATA_DIR} ${ANOMYLIB}
	${INSTALL_DATA_DIR} ${ANOMYLIB}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sanitizer.pl ${ANOMYLIB}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/simplify.pl ${ANOMYLIB}/bin
	cd ${WRKSRC}/bin && ${PAX} -rw -s',.*\.orig$$,,' Anomy ${ANOMYLIB}/bin
	${CHMOD} -R u=rw,go=r ${ANOMYLIB}/bin/Anomy
	${CHMOD} -R a+X ${ANOMYLIB}/bin/Anomy
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${ANOMYLIB}

.include "../../mk/bsd.pkg.mk"
