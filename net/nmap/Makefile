# $NetBSD: Makefile,v 1.148 2023/10/24 22:10:27 wiz Exp $

PKGREVISION= 2
.include "Makefile.common"

COMMENT=	Network/port scanner with OS detection

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=1.0.0
BUILDLINK_API_DEPENDS.libpcre+=	libpcre>=7.6

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-libssh2=${BUILDLINK_PREFIX.libssh2}
CONFIGURE_ARGS+=	--without-ndiff # provided by net/ndiff
CONFIGURE_ARGS+=	--without-subversion
CONFIGURE_ARGS+=	--without-zenmap # provided by net/zenmap

BUILD_DEFS+=		IPV6_READY

TEST_TARGET=		check

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
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
