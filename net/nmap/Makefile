# $NetBSD: Makefile,v 1.58 2008/01/18 05:08:46 tnn Exp $
#

DISTNAME=	nmap-4.20
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://insecure.org/nmap/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://insecure.org/nmap/
COMMENT=	Network/port scanner with OS detection

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILDLINK_API_DEPENDS.libpcap=	libpcap>=0.9.4
BUILDLINK_API_DEPENDS.libpcre=	libpcre>=6.7

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--without-nmapfe

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
MAKE_ENV+=	CPPFLAGS=""
.endif

# The SunPro C++ compiler does not understand __FUNCTION__, as well as
# __func__. So __FILE__ is the nearest replacement.
.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS.SunOS+=	-D__FUNCTION__=__FILE__
.endif

.if empty(PKGSRC_COMPILER:Mgcc)
# The Makefile uses a hard-coded option -MM to get the dependencies, which
# is only understood by the GNU compiler. For a normal build the dependen-
# cies are not needed anyway, only when patching files and fixing bugs.
pre-build:
	${ECHO} "# ignored" > ${WRKSRC}/makefile.dep
.endif

.include "../../devel/pcre/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
