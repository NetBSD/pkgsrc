# $NetBSD: Makefile,v 1.1.1.1 2002/08/20 20:52:29 cjep Exp $
# FreeBSD Id: ports/shells/osh/Makefile,v 1.3 2002/01/29 11:58:43 knu Exp

DISTNAME=	osh-020214
CATEGORIES=	shells
MASTER_SITES=	http://omnibus.ruf.uni-freiburg.de/~gritter/archive/

MAINTAINER=	packages@netbsd.org
COMMENT=	Implementation of the UNIX 6th Edition shell

MAKEFILE=	makefile

post-install:
	@${ECHO} "updating /etc/shells";				\
	${TOUCH} /etc/shells;						\
	${CP} /etc/shells /etc/shells.bak;				\
	(${GREP} -v '${PREFIX}/bin/osh' /etc/shells.bak || ${TRUE}; 	\
		${ECHO} "${PREFIX}/bin/osh") > /etc/shells

.include "../../mk/bsd.pkg.mk"
