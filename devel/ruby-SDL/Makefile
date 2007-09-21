# $NetBSD: Makefile,v 1.1.1.1 2007/09/21 10:14:37 taca Exp $
#

DISTNAME=	rubysdl-${VERS}
PKGNAME=	${RUBY_PKGPREFIX}-SDL-${VERS}
CATEGORIES=	devel audio graphics ruby
MASTER_SITES=	http://www.kmc.gr.jp/~ohai/rubysdl/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.kmc.gr.jp/~ohai/rubysdl.en.html
COMMENT=	Ruby extension library to use SDL library

VERS=		1.3.1

USE_RUBY_EXTCONF=	yes
INSTALLATION_DIRS=	${RUBY_DOCDIR}/doc/sdl/ja ${RUBY_DOCDIR}/examples/sdl

RD_SRCS=	rubysdl_doc.en.rd rubysdl_doc_old.rd
DOCS_EN=	NEWS.en README.en rubysdl_const_list.txt \
		rubysdl_doc.en.html rubysdl_doc.en.rd
DOCS_JA=	NEWS.ja README.ja rubysdl_doc_old.html rubysdl_doc_old.rd \
		rubysdl_ref.html rubysdl_ref.rd

post-build:
.for f in ${RD_SRCS}
	cd ${WRKSRC}; ${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor

post-install:
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${RUBY_DOCDIR}/doc/sdl
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${RUBY_DOCDIR}/doc/sdl/ja
.endfor
	cd ${WRKSRC}/sample; ${INSTALL_DATA} * \
		${DESTDIR}${RUBY_DOCDIR}/examples/sdl

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
