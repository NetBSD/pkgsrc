# $NetBSD: Makefile,v 1.26 2004/03/31 12:37:00 recht Exp $

DISTNAME=		balsa-2.0.17
CATEGORIES=		mail gnome
MASTER_SITES=		http://balsa.gnome.org/				\
			ftp://ftp.newton.cx/pub/balsa/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://balsa.gnome.org/
COMMENT=		GNOME2 EMail client

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome-dirs>=1.5:../../misc/gnome-dirs

USE_PERL5=		build
USE_PKGINSTALL=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-gpgme=${BUILDLINK_PREFIX.gpgme}/bin/gpgme-config
CONFIGURE_ARGS+=	--disable-more-warnings
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--enable-pcre
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		ac_cv_lib_iconv_iconv_open=yes

EGDIR=		${PREFIX}/share/examples/balsa
.for cnf in balsa.soundlist email.soundlist
CONF_FILES+=	${EGDIR}/${cnf} ${PKG_SYSCONFDIR}/sound/events/${cnf}
.endfor

.include "../../mk/bsd.prefs.mk"

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
CONFIGURE_ARGS+=        --with-ldap
.include "../../databases/openldap/buildlink3.mk"
.endif
BUILD_DEFS+=	USE_OPENLDAP

.include "../../security/gpgme/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/gtkhtml3/buildlink3.mk"
.include "../../mail/libesmtp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
