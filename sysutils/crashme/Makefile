# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:49 agc Exp $
#

DISTNAME=       	crashme-2.4
CATEGORIES=		devel
MASTER_SITES=   	http://ochimizu-www.jaist.ac.jp:8000/linux/vger/crashme/
EXTRACT_SUFX=		-shar

MAINTAINER=		agc@netbsd.org

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
MAKEFILE=		makefile

MAN1=			crashme.1

.include "../../mk/bsd.pkg.mk"
