# $NetBSD: Makefile,v 1.1.1.1 2002/07/23 14:26:54 agc Exp $
#

DISTNAME=		jed-B0.99-15
PKGNAME=		xjed-0.99.15
CATEGORIES=		editors
MASTER_SITES=		ftp://space.mit.edu/pub/davis/jed/v0.99/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://space.mit.edu/~davis/jed.html
COMMENT=		X11-based text editor, extensible through S-Lang functions

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-x

WRKSRC=			${WRKDIR}/jed-B0.99-15

post-install:
	@cd ${WRKSRC};							\
		for dir in lib info doc; do				\
			${ECHO} "Installing $$dir files";		\
			${PAX} -rwpe $$dir ${PREFIX}/share/xjed;	\
		done
	${RM} -f ${PREFIX}/share/xjed/doc/jed.1 ${PREFIX}/share/xjed/doc/rgrep.1
	${RMDIR} ${PREFIX}/share/xjed/bin

.include "../../devel/libslang/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
