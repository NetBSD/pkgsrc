# $NetBSD: Makefile,v 1.5 2001/02/16 14:38:39 wiz Exp $
#

DISTNAME=	libsmi-0.1.6
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/libsmi/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.ibr.cs.tu-bs.de/projects/libsmi/
COMMENT=	Library to access SMI MIB information

MIBDIR=		${PREFIX}/share/libsmi/mibs

USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-mibdir="${MIBDIR}"
# this might make it easier to use scotty's and ucd-snmp's mibs,
# and local ones too
CONFIGURE_ARGS+=--with-smipath="${MIBDIR}:${PREFIX}/share/snmp/mibs:${PREFIX}/lib/tnm2.1.8/mibs:/usr/local/share/snmp/mibs"

# Only for systems that don't have these:
.include "../../mk/bsd.prefs.mk"
.if ${OS_VERSION:M1.4} || ${OS_VERSION:M1.3} || ${OS_VERSION:M1.2}
CPPFLAGS+=	-Dstrtoll=strtoq -Dstrtoull=strtouq
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
.endif

.include "../../mk/bsd.pkg.mk"
