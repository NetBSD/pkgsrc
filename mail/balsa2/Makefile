# $NetBSD: Makefile,v 1.11 2003/11/12 03:39:40 jschauma Exp $
#

DISTNAME=		balsa-2.0.15
PKGREVISION=		2
CATEGORIES=		mail gnome
MASTER_SITES=		http://balsa.gnome.org/				\
			ftp://ftp.newton.cx/pub/balsa/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://balsa.gnome.org/
COMMENT=		GNOME2 EMail client

BUILD_USES_MSGFMT=	yes

USE_PERL5=		build
USE_PKGINSTALL=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-gpgme=${BUILDLINK_PREFIX.gpgme}
CONFIGURE_ARGS+=	--disable-more-warnings
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--enable-pcre
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/balsa
.for cnf in balsa.soundlist email.soundlist
CONF_FILES+=	${EGDIR}/${cnf} ${PKG_SYSCONFDIR}/sound/events/${cnf}
.endfor

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
CONFIGURE_ARGS+=        --enable-ldap
.include "../../databases/openldap/buildlink2.mk"
.endif

.include "../../converters/libiconv/buildlink2.mk"
.if ${_BLNK_LIBICONV_FOUND} == "YES" || ${_NEED_ICONV} == "YES"
CONFIGURE_ENV+=	ac_cv_lib_iconv_iconv_open=yes
.endif

.include "../../security/gpgme/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../mail/libesmtp/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
