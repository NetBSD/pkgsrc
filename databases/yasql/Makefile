# $NetBSD: Makefile,v 1.3 2005/06/16 06:57:44 jlam Exp $

DISTNAME=	yasql-1.81
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yasql/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://yasql.sourceforge.net/
COMMENT=	Yet another SQLPlus replacement for Oracle

USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes
NO_BUILD=	# defined

CONFIGURE_ARGS+=--prefix=${PREFIX}
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}

DEPENDS+=	p5-DBD-Oracle-[0-9]*:../../databases/p5-DBD-Oracle
DEPENDS+=	p5-Term-ReadLine-[0-9]*:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

CONF_FILES+=	${PREFIX}/share/examples/yasql/yasql.conf \
		${PKG_SYSCONFDIR}/yasql.conf

INSTALLATION_DIRS=	bin man/man1

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} default

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yasql ${PREFIX}/bin/yasql
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/yasql
	${INSTALL_DATA} ${WRKSRC}/yasql.conf \
		${PREFIX}/share/examples/yasql/yasql.conf
	${INSTALL_MAN} ${WRKSRC}/yasql.1 ${PREFIX}/man/man1/yasql.1

.include "../../mk/bsd.pkg.mk"
