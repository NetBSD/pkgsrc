# $NetBSD: Makefile,v 1.3 2002/01/22 17:06:19 taca Exp $
# FreeBSD: ports/lang/ruby14/Makefile,v 1.36 2000/09/26 09:34:52 knu ExP

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}base-${RUBY_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT= 	base installation of Ruby 1.4

DIST_SUBDIR=	ruby
USE_RUBY=	yes
RUBY_DEPENDS=	no
RUBY_BUILD_DEPENDS= no

RUBY_VER=	1.4

GNU_CONFIGURE=	yes
WRKSRC=		${RUBY_WRKSRC}
CONFIGURE_ARGS=	--enable-shared
MLINKS=		ruby${_RUBY_SUFFIX}.1 ruby.1

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

pre-build:
	@${FIND} ${WRKSRC} -name '*.orig' -exec rm -f {} \;

post-build:
	${SED} -e 's|#!/usr/local/bin/ruby|#!${RUBY}|' \
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
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/irb.rb ${PREFIX}/bin/irb${_RUBY_SUFFIX}
	${RM} -f ${WRKSRC}/sample/irb.rb
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/curses
	${INSTALL_DATA} ${WRKSRC}/ext/curses/hello.rb \
		${WRKSRC}/ext/curses/rain.rb \
		${WRKSRC}/ext/curses/view.rb \
		${RUBY_EXAMPLESDIR}/curses
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/ext/pty/expect_sample.rb \
		${WRKSRC}/ext/pty/script.rb \
		${WRKSRC}/ext/pty/shl.rb \
		${RUBY_EXAMPLESDIR}/pty
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${RUBY_DOCDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/ext/etc/etc.txt* ${RUBY_DOCDIR}/etc
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/ext/pty/README* ${RUBY_DOCDIR}/pty

test:
	@(cd ${WRKSRC}; make test)

.include "../../mk/bsd.pkg.mk"
