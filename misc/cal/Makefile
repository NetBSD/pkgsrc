# $NetBSD: Makefile,v 1.5 1998/06/22 12:52:31 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/05/12 06:33:23 max Exp
#

DISTNAME=		cal-3.5
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/shell

MAINTAINER=		packages@netbsd.org

WRKSRC=			${WRKDIR}/cal-3.5/source
MAKEFILE=		makefile.unx
ALL_TARGET=		cal

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cal ${PREFIX}/bin/cal
	${INSTALL_MAN}  ${WRKSRC}/cal.1 ${PREFIX}/man/man1/cal.1
	@${MKDIR} ${PREFIX}/etc/cal
	@chmod 0755  ${PREFIX}/etc/cal
	if [ ! -f ${PREFIX}/etc/cal/calcol ]; then ${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.col ${PREFIX}/etc/cal/calcol; fi
	if [ ! -f ${PREFIX}/etc/cal/caldat ]; then ${INSTALL_DATA} ${WRKDIR}/cal-3.5/cal.dat ${PREFIX}/etc/cal/caldat; fi

.include "../../mk/bsd.pkg.mk"
