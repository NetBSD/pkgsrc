# $NetBSD: Makefile,v 1.33 2016/04/18 17:49:20 bsiegert Exp $

DISTNAME=	duplicity-0.7.07
CATEGORIES=	sysutils net
MASTER_SITES=	http://code.launchpad.net/duplicity/0.7-series/${PKGVERSION_NOREV}/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/duplicity/
COMMENT=	Remote encrypting incremental backup utility
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes

.include "options.mk"

DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.9.1:../../devel/py-lockfile

REPLACE_PYTHON+=	bin/duplicity \
			bin/rdiffdir
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.6.22

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	fixing hard coded dirs
SUBST_FILES.fix-paths=		setup.py
SUBST_SED.fix-paths=		-e 's,share/man/man1,${PKGMANDIR}/man1,'
SUBST_SED.fix-paths+=		-e 's,share/locale,${PKGLOCALEDIR}/locale,'

SUBST_CLASSES+=			gpgpath
SUBST_STAGE.gpgpath=		pre-configure
SUBST_FILES.gpgpath=		duplicity/gpginterface.py
SUBST_VARS.gpgpath=		GPGPATH

# XXX in 0.6.21, doc files are mode 0600
#post-extract:
#	cd ${WRKSRC} && ${CHMOD} go+r *
# XXX in 0.7.07, executable bit set on duplicity.1
post-extract:
	${CHMOD} -x ${WRKSRC}/bin/duplicity.1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../net/librsync/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
