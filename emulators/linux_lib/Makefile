# $NetBSD: Makefile,v 1.13 1998/08/17 18:14:07 tv Exp $
# FreeBSD Id: Makefile,v 1.19 1997/12/04 17:34:28 asami Exp
#

DISTNAME=		linux_lib-2.4
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}
ONLY_FOR_ARCHS=		i386

MAINTAINER=		packages@netbsd.org

# XXX this is not the right thing
.include "../../mk/bsd.pkg.mk"
LOCALBASE=		/emul/linux
NO_MTREE=

# The distfile is distributed under the GPL, so no re-distribution of
# binaries without source.
MIRROR_DISTFILE=	no

NO_MTREE=		yes
NO_BUILD=		yes
EXTRACT_ONLY=		# empty
NO_WRKSUBDIR=		yes

pre-install:
	@[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}

do-install:
	@${GZCAT} ${DISTDIR}/${DISTNAME}.tar.gz |(cd ${PREFIX}; pax -r)

post-install:
	${RM} ${PREFIX}/lib/libc.so.5.4.23
	${LN} -sf libc.so.5.3.12 ${PREFIX}/lib/libc.so.5
	${LN} -sf ../../lib/libc.so.5.3.12 ${PREFIX}/usr/lib/libc.so
	-${PREFIX}/sbin/ldconfig || ${TRUE}
	${MKDIR} ${PREFIX}/usr/lib/zoneinfo
	${LN} -sf /etc/localtime ${PREFIX}/usr/lib/zoneinfo/localtime
	${MKDIR} ${PREFIX}/dev
	${LN} -sf /dev/sound ${PREFIX}/dev/dsp
	${MKDIR} ${PREFIX}/usr/local/lib

.include "../../mk/bsd.pkg.mk"
