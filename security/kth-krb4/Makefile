# $NetBSD: Makefile,v 1.18 2002/07/02 11:41:15 agc Exp $
#

DISTNAME=		krb4-1.1.1
PKGNAME=		kth-krb4-1.1.1 
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=		wennmach@netbsd.org
HOMEPAGE=		http://www.pdc.kth.se/kth-krb/
COMMENT=		Kerberos IV distribution from KTH

# enable this once our autoconf has been upgraded to autoconf>=2.52:
#BUILD_DEPENDS+=	automake>1.4:../../devel/automake  

CONFLICTS+=		wu-ftpd-[0-9]*
CONFLICTS+=		lukemftp-[0-9]*
CONFLICTS+=		zephyr-[0-9]*
CONFLICTS+=		libdes-[0-9]*

CRYPTO=			yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--includedir=${PREFIX}/include/kerberosIV

.include "../../mk/x11.buildlink.mk"
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

# this hangs while compiling one of the files, at least with the
# toolchain as of 1.5ZC (20020329)
.if ${MACHINE_ARCH} == "sparc64"
BROKEN=			toolchain problems on sparc64 (1.5ZC, 20020329)
.endif

post-patch:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		<${WRKSRC}/lib/kafs/kafs.h                                    \
		>${WRKSRC}/lib/kafs/kafs.h.sed
	@${MV} ${WRKSRC}/lib/kafs/kafs.h.sed ${WRKSRC}/lib/kafs/kafs.h

# enable this once our autoconf has been upgraded to autoconf>=2.52:
#pre-configure:
#	cd ${WRKSRC};                                                         \
#	${LOCALBASE}/bin/aclocal;                                             \
#	${LOCALBASE}/bin/autoheader;                                          \
#	${LOCALBASE}/bin/automake -a --foreign -i;                            \
#	${LOCALBASE}/bin/autoconf

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/krb.conf ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/krb.realms ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${WRKSRC}/etc/inetd.conf.changes ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${FILESDIR}/services-1.4.2.diff ${PREFIX}/share/examples/kth-krb4
	${INSTALL_DATA} ${FILESDIR}/services-1.5.diff ${PREFIX}/share/examples/kth-krb4

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
