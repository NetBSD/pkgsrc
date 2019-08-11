# $NetBSD: Makefile,v 1.10 2019/08/11 13:21:30 wiz Exp $
#

DISTNAME=	minimalist-2.5.4-1
PKGNAME=	minimalist-2.5.4.1
PKGREVISION=	6
CATEGORIES=	mail
#MASTER_SITES=	http://www.mml.org.ua/LIST/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.mml.org.ua/
COMMENT=	Minimalistic Mailing Lists Manager
LICENSE=	2-clause-bsd

USE_TOOLS+=	perl
REPLACE_PERL=	${WRKSRC}/minimalist.pl
REPLACE_PERL+=	${WRKSRC}/contrib/minimalist_request.pl

EGDIR=		${PREFIX}/share/examples/minimalist/
CONF_FILES=	${EGDIR}/minimalist.conf ${PKG_SYSCONFDIR}/minimalist.conf

WRKSRC=		${WRKDIR}/${DISTNAME:S/-1/.1/1}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	minimalist.conf-sample
SUBST_FILES.path+=	minimalist.pl
SUBST_FILES.path+=	contrib/minimalist_request.pl
SUBST_SED.path=		-e 's,/usr/local,${PREFIX},'

NO_BUILD=		yes
INSTALLATION_DIRS=	bin ${EGDIR} share/doc/minimalist/FAQ

do-install:
	cd ${WRKSRC}; \
	${INSTALL_DATA} minimalist.conf-sample \
		${DESTDIR}${PREFIX}/share/examples/minimalist/minimalist.conf; \
	${INSTALL_DATA} sample/lists.lst \
		${DESTDIR}${PREFIX}/share/examples/minimalist; \
	${INSTALL_DATA} sample/sample/* \
		${DESTDIR}${PREFIX}/share/examples/minimalist; \
	${INSTALL_DATA} docs/FAQ/* \
		${DESTDIR}${PREFIX}/share/doc/minimalist/FAQ; \
for file in README CHANGES.txt virtual-domains.txt; do \
	${INSTALL_DATA} docs/$${file} \
		${DESTDIR}${PREFIX}/share/doc/minimalist/; \
done; \
	${INSTALL_SCRIPT} minimalist.pl ${DESTDIR}${PREFIX}/bin; \
	${INSTALL_SCRIPT} contrib/minimalist_request.pl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
