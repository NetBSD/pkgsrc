# $NetBSD: Makefile,v 1.15 2004/11/14 10:59:58 soren Exp $
#

DISTNAME=	gnats-4.0.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=gnats/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnats/
COMMENT=	GNATS bug tracking system

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		m4 make
USE_BISON=		yes
USE_MAKEINFO=		yes
TEXINFO_REQD=		4.6
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INFO_FILES=	gnats.info gnats-faq.info

CONFIGURE_ARGS= --with-lispdir=${PREFIX}/share/emacs/site-lisp

GNATS_HOME=	${PREFIX}/share/gnats/gnats-db
PKG_USERS=	gnats:daemon::GNATS\\ database\\ owner:${GNATS_HOME}:${SH}

MAKE_DIRS=		${PREFIX}/share/gnats
MAKE_DIRS+=		${PREFIX}/libexec/gnats
OWN_DIRS_PERMS=		${GNATS_HOME} gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/gnats-queue gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/pending gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/gnats-adm gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/gnats-adm/locks gnats daemon 755

MESSAGE_SUBST+=		PREFIX="${PREFIX}"

.include "../../mk/bsd.pkg.mk"
