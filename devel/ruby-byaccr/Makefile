# $NetBSD: Makefile,v 1.12 2008/03/23 11:08:52 taca Exp $

DISTNAME=	byaccr-0.1
PKGNAME=	ruby-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.idaemons.org/pub/distfiles/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Parser generator for ruby based on 'Berkeley Yacc/Yacc for Java'

PKG_DESTDIR_SUPPORT=	user-destdir

EXAMPLES=	Makefile cal.y calfunc.rb main.rb

INSTALLATION_DIRS=	bin share/examples/byaccr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/byaccr ${DESTDIR}${PREFIX}/bin
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} \
		${DESTDIR}${PREFIX}/share/examples/byaccr
.endfor

.include "../../mk/bsd.pkg.mk"
