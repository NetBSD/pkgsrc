# $NetBSD: Makefile,v 1.39 2022/06/28 11:34:19 wiz Exp $

DISTNAME=	demime-1.1d
PKGREVISION=	11
CATEGORIES=	mail textproc
MASTER_SITES=	${MASTER_SITE_FREEBSD}
DISTFILES=	${DISTNAME:S/-/./} \
		demime_junkmail.cf

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://scifi.squawk.com/demime.html
COMMENT=	Tool to scrub mime from mailing lists

#DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-HTML-Format-[0-9]*:../../www/p5-HTML-Format
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree

DIST_SUBDIR=	${PKGNAME_NOREV}
USE_TOOLS+=	perl:run pod2man

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/demime_junkmail.cf ${PKG_SYSCONFDIR}/demime_junkmail.cf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME:S/-/./} ${WRKSRC}/demime.stable

do-build:
	${SED} -e 's|/usr/lib/majordomo/demime_junkmail.cf|${PKG_SYSCONFDIR}/demime_junkmail.cf|g' \
	       -e 's|/usr/bin/perl|${PERL5}|g' \
	       ${WRKSRC}/demime.stable >${WRKSRC}/demime
	${POD2MAN} ${WRKSRC}/demime > ${WRKSRC}/demime.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/demime ${DESTDIR}${PREFIX}/bin/demime
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/demime_junkmail.cf \
		${DESTDIR}${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/demime.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/demime.1

.include "../../mk/bsd.pkg.mk"
