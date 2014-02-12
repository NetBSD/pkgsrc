# $NetBSD: Makefile,v 1.117 2014/02/12 23:18:24 tron Exp $

DISTNAME=	nmap-6.40
PKGREVISION=	5
CATEGORIES=	net security
MASTER_SITES=	http://nmap.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://insecure.org/nmap/
COMMENT=	Network/port scanner with OS detection
LICENSE=	gnu-gpl-v2

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=1.0.0
BUILDLINK_API_DEPENDS.libpcre+=	libpcre>=7.6
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.8

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--without-subversion

BUILD_DEFS+=		IPV6_READY

.include "options.mk"

CHECK_INTERPRETER_SKIP=		bin/uninstall_zenmap
CHECK_INTERPRETER_SKIP+=	share/zenmap/su-to-zenmap.sh
CHECK_INTERPRETER_SKIP+=	share/nmap/nselib/data/oracle-default-accounts.lst
CHECK_INTERPRETER_SKIP+=	share/nmap/nselib/data/oracle-sids
CHECK_INTERPRETER_SKIP+=	share/nmap/nselib/data/passwords.lst
CHECK_INTERPRETER_SKIP+=	share/nmap/nselib/data/rtsp-urls.txt
CHECK_INTERPRETER_SKIP+=	share/nmap/nselib/data/snmpcommunities.lst

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
#.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
