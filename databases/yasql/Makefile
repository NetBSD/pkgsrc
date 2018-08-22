# $NetBSD: Makefile,v 1.21 2018/08/22 09:43:26 wiz Exp $

DISTNAME=	yasql-1.81
PKGREVISION=	8
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yasql/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yasql.sourceforge.net/
COMMENT=	Yet another SQLPlus replacement for Oracle

DEPENDS+=	p5-DBD-Oracle-[0-9]*:../../databases/p5-DBD-Oracle
#DEPENDS+=	{perl>=5.002,p5-Term-ReadLine-[0-9]*}:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

USE_TOOLS+=	perl:run
GNU_CONFIGURE=	yes
NO_BUILD=	yes

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

CONF_FILES+=	${PREFIX}/share/examples/yasql/yasql.conf \
		${PKG_SYSCONFDIR}/yasql.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} default

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yasql ${DESTDIR}${PREFIX}/bin/yasql
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/yasql
	${INSTALL_DATA} ${WRKSRC}/yasql.conf \
		${DESTDIR}${PREFIX}/share/examples/yasql/yasql.conf
	${INSTALL_MAN} ${WRKSRC}/yasql.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/yasql.1

.include "../../mk/bsd.pkg.mk"
