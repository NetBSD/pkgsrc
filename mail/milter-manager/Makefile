# $NetBSD: Makefile,v 1.1.1.1 2010/04/09 12:40:23 obache Exp $
#

DISTNAME=	milter-manager-1.4.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=milter-manager/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://milter-manager.sourceforge.net/
COMMENT=	Milter to use milters effectively

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool msgfmt
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--with-package-platform=pkgsrc
CONFIGURE_ARGS+=	--with-rcddir=${RCD_SCRIPTS_DIR}
CONFIGURE_ARGS+=	--with-default-effective-user=${MILTER_MANAGER_USER}
CONFIGURE_ARGS+=	--with-default-effective-group=${MILTER_MANAGER_GROUP}
CONFIGURE_ARGS+=	--with-default-socket-group=${MILTER_MANAGER_SOCKET_GROUP}
CONFIGURE_ARGS+=	--with-default-pid-file=${VARBASE}/run/milter-manager/milter-manager.pid
PKG_SYSCONFSUBDIR=	${PKGBASE}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS+=	pkgsysconfdir=${EGDIR}

PKGCONFIG_OVERRIDE+=	libmilter.pc.in
PKGCONFIG_OVERRIDE+=	milter-client.pc.in
PKGCONFIG_OVERRIDE+=	milter-core.pc.in
PKGCONFIG_OVERRIDE+=	milter-manager.pc.in
PKGCONFIG_OVERRIDE+=	milter-server.pc.in

MILTER_MANAGER_USER?=	_milter
MILTER_MANAGER_GROUP?=	_milter
MILTER_MANAGER_SOCKET_GROUP?=	mail
PKG_GROUPS=		${MILTER_MANAGER_GROUP} ${MILTER_MANAGER_SOCKET_GROUP}
PKG_USERS=		${MILTER_MANAGER_USER}:${MILTER_MANAGER_GROUP}
PKG_GECOS.${MILTER_MANAGER_USER}=	Milter Manager
PKG_GROUPS_VARS+=	MILTER_MANAGER_GROUP MILTER_MANAGER_SOCKET_GROUP
PKG_USERS_VARS=		MILTER_MANAGER_USER

OWN_DIRS+=		${PKG_SYSCONFDIR}/applicable-conditions
OWN_DIRS+=		${PKG_SYSCONFDIR}/defaults
OWN_DIRS_PERMS+=	${VARBASE}/run/milter-manager \
			${MILTER_MANAGER_USER} ${MILTER_MANAGER_GROUP} 755

.for conf in milter-manager.conf \
	applicable-conditions/authentication.conf \
	applicable-conditions/remote-network.conf \
	applicable-conditions/restrict-accounts.conf \
	applicable-conditions/s25r.conf \
	applicable-conditions/sendmail-compatible.conf \
	defaults/pkgsrc.conf
CONF_FILES+=	${EGDIR}/${conf} ${PKG_SYSCONFDIR}/${conf}
.endfor

RCD_SCRIPTS=		milter-manager

BUILD_DEFS+=		RCD_SCRIPTS_DIR VARBASE
BUILD_DEFS+=		MILTER_MANAGER_USER
BUILD_DEFS+=		MILTER_MANAGER_GROUP
BUILD_DEFS+=		MILTER_MANAGER_SOCKET_GROUP

REPLACE_RUBY=		admin/public/dispatch.*
.include "../../lang/ruby/replace.mk"

.include "../../lang/ruby/buildlink3.mk"
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.12.3
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
