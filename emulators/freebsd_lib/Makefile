# $NetBSD: Makefile,v 1.3 1998/12/12 18:10:31 frueauf Exp $
#

DISTNAME=		freebsd_lib-2.2.7
CATEGORIES=		emulators
MASTER_SITES=		http://www.flame.org/NetBSD/
ONLY_FOR_ARCHS=		i386

MAINTAINER=		packages@netbsd.org

#
# The distfile is distributed under the GPL, so no re-distribution of
# binaries without source.
#
# Source can be found on
#	http://www.flame.org/NetBSD/freebsd_lib.2.2.7-src.tar.gz.
# It seems nasty to have to provide source when FreeBSD already does.
#
MIRROR_DISTFILE=	no

NO_BUILD=		yes
EXTRACT_ONLY=		# empty
NO_WRKSUBDIR=		yes

EMUL_DIR=	${PREFIX}/emul
FREEBSD_DIR=	${EMUL_DIR}/freebsd

pre-install:
	@[ -d ${EMUL_DIR} ] || ${MKDIR} ${EMUL_DIR}
	@if [ ! -e /emul ] || \
	    [ "`ls -i /emul/.`" != "`ls -i ${EMUL_DIR}`" ]; \
	 then \
	   ${ECHO} -n "You must create a link \"/emul\" "; \
	   ${ECHO} "pointing to \"${EMUL_DIR}\"."; \
	   exit 1; \
	 fi

do-install:
	${MKDIR} ${FREEBSD_DIR}
	(cd ${FREEBSD_DIR}; pax -rzf ${DISTDIR}/${DISTNAME}.tar.gz)

.include "../../mk/bsd.pkg.mk"
