# $NetBSD: Makefile,v 1.11 2006/09/03 00:56:29 wiz Exp $
#

DISTNAME=	libsmi-0.1.6
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/libsmi/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ibr.cs.tu-bs.de/projects/libsmi/
COMMENT=	Library to access SMI MIB information

MIBDIR=		${PREFIX}/share/libsmi/mibs

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-mibdir=${MIBDIR:Q}
# this might make it easier to use scotty's and ucd-snmp's mibs,
# and local ones too
CONFIGURE_ARGS+=--with-smipath="${MIBDIR}:${PREFIX}/share/snmp/mibs:${PREFIX}/lib/tnm2.1.8/mibs:/usr/local/share/snmp/mibs"

# Only for systems that don't have these:
.include "../../mk/bsd.prefs.mk"
.if ${OS_VERSION:M1.4} || ${OS_VERSION:M1.3} || ${OS_VERSION:M1.2}
CPPFLAGS+=	-Dstrtoll=strtoq -Dstrtoull=strtouq
.endif

.include "../../mk/bsd.pkg.mk"
