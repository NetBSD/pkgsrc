# $NetBSD: Makefile,v 1.1.1.1 1999/09/08 07:59:18 sakamoto Exp $
#

DISTNAME=	libsmi-0.1.6
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/libsmi/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.ibr.cs.tu-bs.de/projects/libsmi/

MIBDIR=		${PREFIX}/share/libsmi/mibs

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	-Dstrtoll=strtoq -Dstrtoull=strtouq
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=--with-mibdir="${MIBDIR}"
# this might make it easier to use scotty's and ucd-snmp's mibs,
# and local ones too
CONFIGURE_ARGS+=--with-smipath="${MIBDIR}:${PREFIX}/share/snmp/mibs:${PREFIX}/lib/tnm2.1.8/mibs:/usr/local/share/snmp/mibs"

post-configure:
	@(cd ${WRKSRC}; ${RM} -f libtool; ${LN} -s ${LIBTOOL} libtool)

.include "../../mk/bsd.pkg.mk"
