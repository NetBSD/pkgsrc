# $NetBSD: Makefile,v 1.4 2011/02/25 09:47:27 wiz Exp $
#
.include "../../news/hellanzb/Makefile.version"

DISTNAME=		hellanzb-${HELLANZB_VERSION}.${HELLANZB_SVN_REV}
PKGREVISION=		2
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		bjs@NetBSD.org
HOMEPAGE=		http://www.hellanzb.com/trac
COMMENT=		Command line nntp file grabber

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-twisted>=1.3:../../net/py-twisted
DEPENDS+=	par2>=0.4:../../archivers/par2
DEPENDS+=	unrar>=3.5.4:../../archivers/unrar

PYDISTUTILSPKG=	yes

PYTHON_VERSIONS_ACCEPTED=	27 26 25 24

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
WRKSRC=		${WRKDIR}/hellanzb-${HELLANZB_VERSION}-trunk

CONF_FILES=	${EGDIR}/hellanzb.conf ${PKG_SYSCONFDIR}/hellanzb.conf

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	${WRKDIR}/hellanzb.conf
SUBST_MESSAGE.conf=	Performing pathname substitutions in hellanzb.conf.
SUBST_STAGE.conf=	pre-install
SUBST_VARS.conf=	PREFIX

post-extract:
	${CP} ${FILESDIR}/hellanzb.conf ${WRKDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/hellanzb.conf ${DESTDIR}${EGDIR}

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
