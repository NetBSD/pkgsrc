# $NetBSD: Makefile,v 1.40 2004/10/03 00:13:16 tv Exp $

DISTNAME=	minicom-1.83.1.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_BACKUP}
#MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/serialcomm/dialout/} \
#		http://www.pp.clinet.fi/~walker/

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=	http://alioth.debian.org/projects/minicom/
COMMENT=	MS-DOS Telix serial communication program "workalike"

BUILD_USES_MSGFMT=	yes
DEPENDS+=	gkermit-[0-9]*:../../comms/gkermit
DEPENDS+=	lrzsz-[0-9]*:../../comms/lrzsz

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}/src
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
