# $NetBSD: Makefile,v 1.27 2003/11/12 03:39:42 jschauma Exp $
#

DISTNAME=		krb4-1.2.1
PKGNAME=		kth-krb4-1.2.1
PKGREVISION=		1
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://www.pdc.kth.se/kth-krb/
COMMENT=		Kerberos IV distribution from KTH

# enable this once our autoconf has been upgraded to autoconf>=2.52:
# (don't forget to also add automake.mk (see bottom))
#AUTOCONF_REQD=		2.52
#AUTOMAKE_REQD=		1.7

CONFLICTS+=		wu-ftpd-[0-9]*
CONFLICTS+=		lukemftp-[0-9]*
CONFLICTS+=		zephyr-[0-9]*
CONFLICTS+=		libdes-[0-9]*

CRYPTO=			yes

USE_BUILDLINK2=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--includedir=${PREFIX}/include/kerberosIV

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

INFO_FILES=		kth-krb.info

EXAMPLEDIR=		${PREFIX}/share/examples/kth-krb4

# this hangs while compiling one of the files, at least with the
# toolchain as of 1.5ZC (20020329)
.if ${MACHINE_ARCH} == "sparc64"
BROKEN=			toolchain problems on sparc64 (1.5ZC, 20020329)
.endif

post-patch:
	@for file in ${WRKSRC}/lib/kafs/kafs.h; do			\
		${SED}	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'	\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

# enable this once our autoconf has been upgraded to autoconf>=2.52:
#pre-configure:
#	cd ${WRKSRC};							\
#	${ACLOCAL};							\
#	${AUTOHEADER};							\
#	${AUTOMAKE} -a --foreign -i;					\
#	${AUTOCONF}

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/krb.conf ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/krb.realms ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/inetd.conf.changes ${EXAMPLEDIR}
	${INSTALL_DATA} ${FILESDIR}/services-1.4.2.diff ${EXAMPLEDIR}
	${INSTALL_DATA} ${FILESDIR}/services-1.5.diff ${EXAMPLEDIR}

# Enable line below once it's needed
#.include "../../mk/automake.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
