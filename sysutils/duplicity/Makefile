# $NetBSD: Makefile,v 1.36 2016/07/09 13:04:06 wiz Exp $

DISTNAME=	duplicity-0.7.08
CATEGORIES=	sysutils net
MASTER_SITES=	http://code.launchpad.net/duplicity/0.7-series/${PKGVERSION_NOREV}/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/duplicity/
COMMENT=	Remote encrypting incremental backup utility
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes

.include "options.mk"

DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.9.1:../../devel/py-lockfile
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko

REPLACE_PYTHON+=	bin/duplicity \
			bin/rdiffdir
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.6.22
EGG_NAME=			${DISTNAME:S/08/8/}

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

# XXX in 0.7.07, executable bit set on duplicity.1
post-extract:
	${CHMOD} -x ${WRKSRC}/bin/duplicity.1
	${CHMOD} go+r ${WRKSRC}/bin/*.1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../net/librsync/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
