# $NetBSD: Makefile,v 1.1.1.1 2001/06/30 08:07:10 taca Exp $
# FreeBSD Id: ports/lang/ruby/Makefile,v 1.39 2000/10/20 19:56:03 knu Exp

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}base-${RUBY_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT= 	base installation of Ruby

BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf

DIST_SUBDIR=	ruby
USE_RUBY=	yes
RUBY_DEPENDS=	no
RUBY_BUILD_DEPENDS= no
DIST_SUBDIR=	ruby

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${RUBY_WRKSRC}
CONFIGURE_ARGS=	--enable-shared
MLINKS=		ruby${_RUBY_SUFFIX}.1 ruby.1

DOCS=		README README.EXT README.EXT.jp README.jp ToDo \
		doc/NEWS doc/forwardable.rd doc/forwardable.rd.jp \
		doc/shell.rd doc/shell.rd.jp
DOCS_ETC=	etc.txt etc.txt.jp
DOCS_PTY=	README README.expect README.expect.jp README.jp

.include "../../lang/ruby-base/Makefile.common"

.if !empty(RUBY_SUFFIX)
CONFIGURE_ARGS+= --program-suffix="${RUBY_SUFFIX}"
.endif

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+= --enable-ipv6
.endif

pre-configure:
	${RM} -f ${WRKSRC}/ext/gdbm/MANIFEST
	${RM} -f ${WRKSRC}/ext/md5/MANIFEST
	${RM} -f ${WRKSRC}/ext/readline/MANIFEST
	${RM} -f ${WRKSRC}/ext/tcltklib/MANIFEST
	${RM} -f ${WRKSRC}/ext/tk/MANIFEST
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoreconf

pre-build:
	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} -f {} \;

post-build:
	${SED} -e 's|#!/usr/bin/env ruby|#!${RUBY}|' \
		${WRKSRC}/sample/irb.rb > ${WRKDIR}/irb.rb

post-install:
	strip ${RUBY}
.if empty(RUBY_SUFFIX)
	${MV} ${RUBY} ${RUBY}${_RUBY_SUFFIX}
	${LN} -fs ruby${_RUBY_SUFFIX} ${RUBY}
	${MV} ${PREFIX}/man/man1/ruby.1 ${PREFIX}/man/man1/ruby${_RUBY_SUFFIX}.1
.else
	${LN} -fs ${RUBY_NAME} ${PREFIX}/bin/ruby
.endif
	${LN} -fs ruby${_RUBY_SUFFIX}.1 ${PREFIX}/man/man1/ruby.1
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/irb.rb ${PREFIX}/bin/irb
	${RM} -f ${WRKSRC}/sample/irb.rb
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/curses
	${INSTALL_DATA} ${RUBY_WRKSRC}/ext/curses/hello.rb \
		${RUBY_WRKSRC}/ext/curses/rain.rb \
		${RUBY_WRKSRC}/ext/curses/view.rb \
		${RUBY_EXAMPLESDIR}/curses
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/ext/pty/expect_sample.rb \
		${WRKSRC}/ext/pty/script.rb ${WRKSRC}/ext/pty/shl.rb \
		${RUBY_EXAMPLESDIR}/pty
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/etc
.for f in ${DOCS_ETC}
	${INSTALL_DATA} ${WRKSRC}/ext/etc/${f} ${RUBY_DOCDIR}/etc
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/pty
.for f in ${DOCS_PTY}
	${INSTALL_DATA} ${WRKSRC}/ext/pty/${f} ${RUBY_DOCDIR}/pty
.endfor

test:
	@(cd ${WRKSRC}; make test)

.include "../../mk/bsd.pkg.mk"
