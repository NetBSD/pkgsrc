# $NetBSD: Makefile,v 1.7 2002/03/21 16:29:19 fredb Exp $
# FreeBSD Id: ports/lang/ruby/Makefile,v 1.39 2000/10/20 19:56:03 knu Exp

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}base-${RUBY_VERSION}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT= 	base installation of Ruby

DIST_SUBDIR=	ruby
USE_RUBY=	yes
RUBY_DEPENDS=	no
RUBY_BUILD_DEPENDS= no
DIST_SUBDIR=	ruby

GNU_CONFIGURE=	yes
WRKSRC=		${RUBY_WRKSRC}
CONFIGURE_ARGS=	--enable-shared
MLINKS=		ruby${_RUBY_SUFFIX}.1 ruby.1

DOCS=		ChangeLog README README.EXT README.EXT.ja README.ja ToDo \
		doc/NEWS doc/forwardable.rd doc/forwardable.rd.ja \
		doc/shell.rd doc/shell.rd.ja doc/irb/irb-tools.rd.ja \
		doc/irb/irb.rd doc/irb/irb.rd.ja doc/net/http.rd.ja \
		doc/net/pop.rd.ja doc/net/smtp.rd.ja doc/shell.rd \
		doc/shell.rd.ja
EXT_DOCS=	ext/etc/etc.txt ext/etc/etc.txt.ja ext/pty/README \
		ext/pty/README.expect ext/pty/README.expect.ja \
		ext/pty/README.ja ext/syslog/syslog.txt

REPLACE_RUBY=	ext/curses/hello.rb ext/curses/rain.rb ext/curses/view.rb \
		lib/matrix.rb sample/biorhythm.rb sample/cal.rb \
		sample/exyacc.rb sample/from.rb sample/fullpath.rb \
		sample/goodfriday.rb sample/irb.rb sample/less.rb \
		sample/mine.rb sample/mpart.rb sample/observ.rb \
		sample/pi.rb sample/rcs.rb sample/test.rb \
		sample/time.rb sample/trojan.rb sample/uumerge.rb

.include "Makefile.common"

.if !empty(RUBY_SUFFIX)
CONFIGURE_ARGS+= --program-suffix="${RUBY_SUFFIX}"
.endif

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+= --enable-ipv6
.endif

pre-configure:
	${RM} -f ${WRKSRC}/ext/gdbm/MANIFEST
	${RM} -f ${WRKSRC}/ext/digest/MANIFEST
	${RM} -f ${WRKSRC}/ext/digest/md5/MANIFEST
	${RM} -f ${WRKSRC}/ext/digest/rmd160/MANIFEST
	${RM} -f ${WRKSRC}/ext/digest/sha1/MANIFEST
	${RM} -f ${WRKSRC}/ext/digest/sha2/MANIFEST
	${RM} -f ${WRKSRC}/ext/readline/MANIFEST
	${RM} -f ${WRKSRC}/ext/tcltklib/MANIFEST
	${RM} -f ${WRKSRC}/ext/tk/MANIFEST

pre-build:
	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} -f {} \;

post-build:
	${MV} -f ${WRKSRC}/sample/irb.rb ${WRKDIR}/irb.rb

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
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/etc
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/irb
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/net
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/pty
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/syslog
.for f in ${DOCS} ${EXT_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${f:C/^(doc|ext)\///}
.endfor

test:
	@(cd ${WRKSRC}; make test)

.include "../../mk/bsd.pkg.mk"
