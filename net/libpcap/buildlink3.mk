# $NetBSD: buildlink3.mk,v 1.26 2025/01/24 19:22:02 riastradh Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	libpcap

.if !defined(LIBPCAP_BUILDLINK3_MK)
LIBPCAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.5.0
BUILDLINK_ABI_DEPENDS.libpcap+=	libpcap>=1.3.0nb1
BUILDLINK_PKGSRCDIR.libpcap?=	../../net/libpcap

# Headers require Availability.h, which debuted with 10.5.
.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100500
.  include "../../devel/macports-legacy-support/buildlink3.mk"
.endif

# on Solaris, we always need libnsl and libsocket because libpcap.a
# references symbols in them.
.if ${OPSYS} == "SunOS"
BUILDLINK_LDADD.libpcap+=	-lnsl -lsocket
BUILDLINK_LDFLAGS.libpcap?=	${BUILDLINK_LDADD.libpcap}
.endif

# NetBSD 9.0 shipped with an oopsie in pcap-config -- various
# @variables@ like @PACKAGE_NAME@ were not substituted.
.if ${OPSYS} == "NetBSD" && ${OS_VERSION:M9.*}
CHECK_BUILTIN.libpcap:=		yes
.  include "../../net/libpcap/builtin.mk"
CHECK_BUILTIN.libpcap:=		no
.  if ${USE_BUILTIN.libpcap:U:tl} == "yes"
TOOLS_CREATE+=			pcap-config
TOOLS_SCRIPT.pcap-config+=	/usr/bin/pcap-config "$$@" | /usr/bin/sed \
	-e 's|@PACKAGE_NAME@|pcap|g' \
	-e 's|@V_RPATH_OPT@|-Wl,-rpath,|g' \
	-e 's|@exec_prefix@|/usr|g' \
	-e 's|@prefix@|/usr|g' \
	# end of sed
.  endif
.endif

.endif # LIBPCAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpcap
