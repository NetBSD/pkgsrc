# $NetBSD: Makefile,v 1.5 2001/03/04 17:33:42 jtb Exp $

DISTNAME=	chemtool-1.3
CATEGORIES=	biology
MASTER_SITES=	http://www.uni-ulm.de/~s_tvolk/chemtool/src/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.uni-ulm.de/~s_tvolk/chemtool.html
COMMENT=	Program for drawing organic molecules

DEPENDS+=	gtk+>=1.0.0:../../x11/gtk

MAKE_ENV+=	"PKGLOCALEDIR=${PKGLOCALEDIR}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/chemtool
	@for f in ${WRKSRC}/examples/*;	do				\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/examples/chemtool/";	\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/chemtool
	@for f in README TODO; do					 \
	i="${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/chemtool/"; \
	${ECHO} $$i; $$i;						 \
	done

.include "../../mk/bsd.pkg.mk"
