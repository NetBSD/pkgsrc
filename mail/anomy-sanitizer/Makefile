# $NetBSD: Makefile,v 1.1.1.1 2002/07/20 20:28:23 kim Exp $
#

DISTNAME=	anomy-sanitizer-1.49
CATEGORIES=	mail
MASTER_SITES=	http://mailtools.anomy.net/dist/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://mailtools.anomy.net/
COMMENT=	Mail message filter and sanitizer

DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=	# defined
NO_PATCH=	# defined
USE_PERL5=	# defined

WRKSRC=		${WRKDIR}/anomy

ANOMYLIB=	${PREFIX}/lib/anomy-sanitizer
ANOMYDOC=	${PREFIX}/share/doc/anomy-sanitizer

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
	${INSTALL_SCRIPT} ${WRKSRC}/sanitizer ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/simplify ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${ANOMYDOC}
	cd ${WRKSRC} && ${PAX} -rw \
	    CHANGELOG.sanitizer \
	    CREDITS \
	    README.sanitizer \
	    contrib \
	    sanitizer.html \
	    testcases \
	    ${ANOMYDOC}
	${CHMOD} -R u=rw,go=r ${ANOMYDOC}
	${CHMOD} -R a+X ${ANOMYDOC}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${ANOMYDOC}
	${INSTALL_DATA_DIR} ${ANOMYLIB}
	${INSTALL_DATA_DIR} ${ANOMYLIB}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sanitizer.pl ${ANOMYLIB}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/simplify.pl ${ANOMYLIB}/bin
	cd ${WRKSRC}/bin && ${PAX} -rw Anomy ${ANOMYLIB}/bin
	${CHMOD} -R u=rw,go=r ${ANOMYLIB}/bin/Anomy
	${CHMOD} -R a+X ${ANOMYLIB}/bin/Anomy
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${ANOMYLIB}

.include "../../mk/bsd.pkg.mk"
