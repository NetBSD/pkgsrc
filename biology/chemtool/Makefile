# $NetBSD: Makefile,v 1.1.1.1 2000/11/25 20:10:55 jtb Exp $

DISTNAME=	chemtool-1.2
CATEGORIES=	biology
MASTER_SITES=	http://www.uni-ulm.de/~s_tvolk/chemtool/stable/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.uni-ulm.de/~s_tvolk/chemtool/

DEPENDS+=	gtk+>=1.0.0:../../x11/gtk

USE_IMAKE=	YES
USE_X11BASE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chemtool ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/chemtool
	@(cd ${WRKSRC};							\
	for i in examples/*;						\
	do								\
	${INSTALL_DATA} $$i ${PREFIX}/share/examples/chemtool;		\
	done;								\
	for j in README TODO ChangeLog;					\
	do								\
	${INSTALL_DATA} $$j ${PREFIX}/share/doc/chemtool;		\
	done)

.include "../../mk/bsd.pkg.mk"
