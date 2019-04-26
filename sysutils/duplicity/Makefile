# $NetBSD: Makefile,v 1.47 2019/04/26 14:12:45 maya Exp $

DISTNAME=	duplicity-0.7.17
PKGREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://code.launchpad.net/duplicity/0.7-series/${PKGVERSION_NOREV}/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/duplicity/
COMMENT=	Remote encrypting incremental backup utility
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes

.include "options.mk"

DEPENDS+=	lftp-[0-9]*:../../net/lftp
DEPENDS+=	ncftp3-[0-9]*:../../net/ncftp3
DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	${PYPKGPREFIX}-boto-[0-9]*:../../net/py-boto
DEPENDS+=	${PYPKGPREFIX}-dropbox-[0-9]*:../../net/py-dropbox
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib-[0-9]*:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-fasteners-[0-9]*:../../devel/py-fasteners
DEPENDS+=	${PYPKGPREFIX}-cloudfiles-[0-9]*:../../www/py-cloudfiles
DEPENDS+=	${PYPKGPREFIX}-swiftclient-[0-9]*:../../www/py-swiftclient
DEPENDS+=	${PYPKGPREFIX}-gdata-[0-9]*:../../www/py-gdata
.include "../../net/librsync/buildlink3.mk"

REPLACE_PYTHON+=	bin/duplicity \
			bin/rdiffdir
PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 0.6.22
EGG_NAME=			${DISTNAME:S/09/9/}

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

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
