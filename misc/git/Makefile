# $NetBSD: Makefile,v 1.9 1998/04/17 09:37:24 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1996/11/21 11:54:39 asami Exp
#

DISTNAME=	git-4.3.17
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	${MACHINE_ARCH}--netbsd
MAN1=		git.1 gitaction.1 gitkeys.1 gitmount.1 gitps.1 gitrgrep.1 \
		gitunpack.1 gitview.1
INFO_FILES=	git

pre-install:
	(cd ${WRKSRC}/info ; ${MAKE} info )
	${CP} ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25
	(cd ${WRKSRC}/term ; ${PATCH} --quiet -p0 <${FILESDIR}/gitrc.cons25.patch )

post-install:
	${MKDIR} ${PREFIX}/share/doc
	${MV} ${PREFIX}/lib/git/html ${PREFIX}/share/doc/git

.include "../../mk/bsd.pkg.mk"
