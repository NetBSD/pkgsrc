# $NetBSD: Makefile,v 1.12 2006/10/16 23:39:50 seb Exp $
#

DISTNAME=	libsmi-0.4.5
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/libsmi/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ibr.cs.tu-bs.de/projects/libsmi/
COMMENT=	Library to access SMI MIB information

MIBDIR=		${PREFIX}/share/libsmi/mibs
PIBDIR=		${PREFIX}/share/libsmi/pibs

DEPENDS+=	wget-[0-9]*:../../net/wget

USE_LIBTOOL=	YES
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-mibdir=${MIBDIR:Q}
CONFIGURE_ARGS+=--with-pibdir=${PIBDIR:Q}
# this might make it easier to use scotty's and ucd-snmp's mibs,
# and local ones too
CONFIGURE_ARGS+=--with-smipath="${MIBDIR}:${PREFIX}/share/snmp/mibs:${PREFIX}/lib/tnm2.1.8/mibs:/usr/local/share/snmp/mibs"

REPLACE_SH+=	tools/smicache.in
REPLACE_SH+=	tools/smistrip.in
REPLACE_SH+=	test/*.test.in

TEST_TARGET=	check

# Only for systems that don't have these:
.include "../../mk/bsd.prefs.mk"
.if ${OS_VERSION:M1.4} || ${OS_VERSION:M1.3} || ${OS_VERSION:M1.2}
CPPFLAGS+=	-Dstrtoll=strtoq -Dstrtoull=strtouq
.endif

post-extract:
	${RM} -f ${WRKSRC}/test/smilint-smiv2.test

.include "../../mk/bsd.pkg.mk"
