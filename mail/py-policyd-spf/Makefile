# $NetBSD: Makefile,v 1.1 2016/10/27 12:30:23 jperkin Exp $

VERSION=	1.3.2
DISTNAME=	pypolicyd-spf-${VERSION}
PKGNAME=	${PYPKGPREFIX}-policyd-spf-${VERSION}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypolicyd-spf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pypolicyd-spf
COMMENT=	Python based policy daemon for Postfix SPF checking
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-ipaddr>0:../../devel/py-ipaddr
DEPENDS+=	${PYPKGPREFIX}-authres>0:../../mail/py-authres
DEPENDS+=	${PYPKGPREFIX}-spf>0:../../mail/py-spf

PYTHON_VERSIONS_ACCEPTED=	27 # py-ipaddr, py-spf

DOCDIR=			share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	python-policyd-spf

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	policyd-spf policyd-spf.1 policyd-spf.conf.5
SUBST_FILES.paths+=	policyd-spf.peruser.5 setup.py
SUBST_VARS.paths=	PKGMANDIR PKG_SYSCONFDIR

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

CONF_FILES=		${EGDIR}/policyd-spf.conf ${PKG_SYSCONFDIR}/policyd-spf.conf

PLIST_SUBST+=		DOCDIR=${DOCDIR:Q} PKGBASE=${PKGBASE:Q}
PRINT_PLIST_AWK+=	{ gsub(/${DOCDIR:S|/|\\/|g}/, "$${DOCDIR}"); }
PRINT_PLIST_AWK+=	{ gsub(/${PKGBASE}/, "$${PKGBASE}"); }

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.per_user_whitelisting ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/policyd-spf.conf.commented ${DESTDIR}${EGDIR}/policyd-spf.conf

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
