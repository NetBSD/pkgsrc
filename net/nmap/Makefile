# $NetBSD: Makefile,v 1.128 2016/03/05 11:29:09 jperkin Exp $

DISTNAME=	nmap-7.01
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://nmap.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://insecure.org/nmap/
COMMENT=	Network/port scanner with OS detection
LICENSE=	gnu-gpl-v2

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=1.0.0
BUILDLINK_API_DEPENDS.libpcre+=	libpcre>=7.6
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.8

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-liblinear=${BUILDLINK_PREFIX.liblinear}
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--without-subversion

BUILD_DEFS+=		IPV6_READY

TEST_TARGET+=		check

.include "options.mk"

CHECK_INTERPRETER_SKIP=		bin/uninstall_zenmap
CHECK_INTERPRETER_SKIP+=	share/zenmap/su-to-zenmap.sh
CHECK_INTERPRETER_SKIP+=	share/nmap/nselib/data/oracle-default-accounts.lst
CHECK_INTERPRETER_SKIP+=	share/nmap/nselib/data/oracle-sids
CHECK_INTERPRETER_SKIP+=	share/nmap/nselib/data/passwords.lst
CHECK_INTERPRETER_SKIP+=	share/nmap/nselib/data/rtsp-urls.txt
CHECK_INTERPRETER_SKIP+=	share/nmap/nselib/data/snmpcommunities.lst
CHECK_PORTABILITY_SKIP+=	libpcap/configure
CHECK_PORTABILITY_SKIP+=	zenmap/install_scripts/macosx/launcher.sh

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

# Remove eventual uninstall_ndiff and/or uninstall_zenmap files.
# This also avoids check-interpreter.mk issues with "/usr/bin/env python".
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/uninstall_*

.include "../../devel/pcre/buildlink3.mk"
.include "../../math/liblinear/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
#.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
