# $NetBSD: Makefile,v 1.3 2002/07/06 20:18:26 tv Exp $
# FreeBSD Id: ports/mail/demime/Makefile,v 1.4 2002/03/26 08:18:20 petef Exp

DISTNAME=	demime-0.99c.8
PKGNAME=	demime-0.99.3.8
CATEGORIES=	mail textproc
MASTER_SITES=	http://scifi.squawk.com/
DISTFILES=	demime.stable demime_junkmail.cf

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://scifi.squawk.com/demime.html
COMMENT=	Tool to scrub mime from mailing lists

DEPENDS+=       p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=       p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=       p5-HTML-Format-[0-9]*:../../www/p5-HTML-Format
DEPENDS+=       p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree

DIST_SUBDIR=	${PKGNAME}
NO_BUILD=	YES
USE_BUILDLINK_ONLY=     YES
USE_PERL5=	YES

POD2MAN?=	${PREFIX}/bin/pod2man

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/demime_junkmail.cf ${PKG_SYSCONFDIR}/demime_junkmail.cf

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/demime.stable ${WRKSRC}/demime.stable

post-patch:
	${SED} -e 's|/usr/lib/majordomo/demime_junkmail.cf|${PKG_SYSCONFDIR}/demime_junkmail.cf|g' \
	       -e 's|/usr/bin/perl|${PREFIX}/bin/perl|g' \
	       ${WRKSRC}/demime.stable >${WRKSRC}/demime

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/demime ${PREFIX}/bin/demime
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/demime_junkmail.cf ${EGDIR}
	${POD2MAN} ${WRKSRC}/demime > ${WRKSRC}/demime.1
	${INSTALL_MAN} ${WRKSRC}/demime.1 ${PREFIX}/man/man1/demime.1

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
