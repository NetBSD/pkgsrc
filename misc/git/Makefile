# New ports collection makefile for:	git
# Version required:	4.3.11
# Date created:		12 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $NetBSD: Makefile,v 1.3 1997/12/22 07:45:46 hubertf Exp $
# FreeBSD Id: Makefile,v 1.8 1996/11/21 11:54:39 asami Exp
#

DISTNAME=	git-4.3.11
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	${ARCH}--netbsd
RUN_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
MAN1=		git.1 gitaction.1 gitmount.1 gitcmp.1 gitkeys.1 \
		gitredir.1 gitrgrep.1 gitps.1 gitview.1

pre-install:
	(cd ${WRKSRC}/info ; ${MAKE} info )
	${CP} ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25
	(cd ${WRKSRC}/term ; patch --quiet -p0 <${FILESDIR}/gitrc.cons25.patch )

post-install:
	@install-info ${PREFIX}/info/git.info ${PREFIX}/info/dir


.include <bsd.port.mk>
