# $NetBSD: Makefile,v 1.29 2003/04/27 12:54:16 cjep Exp $
# FreeBSD Id: Makefile,v 1.13 1998/01/03 10:58:40 obrien Exp
#

DISTNAME=	${PKGNAME}.src
PKGNAME=	minicom-1.83.1
WRKSRC=		${WRKDIR}/${PKGNAME}/src
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/serialcomm/dialout/} \
		http://www.pp.clinet.fi/~walker/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.clinet.fi/~walker/minicom.html
COMMENT=	MS-DOS Telix serial communication program "workalike"

BUILD_USES_MSGFMT=	yes
DEPENDS+=	gkermit-[0-9]*:../../comms/gkermit
DEPENDS+=	lrzsz-[0-9]*:../../comms/lrzsz

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
NO_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	minicom
EGDIR=			${PREFIX}/share/examples/minicom

PKG_GROUPS=		dialer
PKG_USERS=		uucp:dialer
SPECIAL_PERMS=		${PREFIX}/bin/minicom uucp dialer 4755
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR} uucp dialer 0755
CONF_FILES_PERMS=	${EGDIR}/minicom.users ${PKG_SYSCONFDIR}/minicom.users \
			uucp dialer 0644

# for BATCH !
.include "../../mk/bsd.prefs.mk"

.if !defined(BATCH)
pre-install:
	# this script creates a link from your comm port to /dev/modem
	${SH} ${SCRIPTDIR}/create-dev-link
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
