# $NetBSD: Makefile,v 1.16 2001/10/25 19:31:10 agc Exp $
#

DISTNAME=		jed-B0.99-15
PKGNAME=		jed-0.99.15
CATEGORIES=		editors
MASTER_SITES=		ftp://space.mit.edu/pub/davis/jed/v0.99/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://space.mit.edu/%7Edavis/jed.html
COMMENT=		Text editor with many features, extensible through S-Lang functions

DEPENDS+=		libslang-[0-9]*:../../devel/libslang

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X

WRKSRC=			${WRKDIR}/jed-B0.99-15

post-install:
	echo "Installing lib files"
	cd ${WRKSRC};							\
		for dir in lib info doc; do				\
			echo "Installing $$dir files";			\
			${PAX} -rwpe $$dir ${PREFIX}/share/jed;		\
		done
	${RM} -f ${PREFIX}/share/jed/doc/jed.1 ${PREFIX}/share/jed/doc/rgrep.1
	${RMDIR} ${PREFIX}/share/jed/bin

.include "../../mk/bsd.pkg.mk"
