# $NetBSD: buildlink2.mk,v 1.3 2003/03/16 19:44:30 jschauma Exp $
#

.if !defined(RUBY_BASE_BUILDLINK2_MK)
RUBY_BASE_BUILDLINK2_MK=	# defined

RUBY_MD_LIBDIR=			${RUBY_ARCH}

BUILDLINK_PACKAGES+=			ruby-base
BUILDLINK_DEPENDS.ruby-base?=		ruby-base>=1.6.7nb3
BUILDLINK_PKGSRCDIR.ruby-base?=		../../lang/ruby-base
EVAL_PREFIX+=	BUILDLINK_PREFIX.ruby-base=ruby-base
BUILDLINK_PREFIX.ruby-base_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ruby-base=	lib/libruby.*
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/config.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/curses.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/dbm.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/defines.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/dln.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/env.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/etc.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/fcntl.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/intern.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/libruby.a
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/nkf.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/node.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/pty.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/rbconfig.rb
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/re.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/regex.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/ruby.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/rubyio.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/rubysig.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/sdbm.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/socket.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/st.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/syslog.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/util.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/${RUBY_MD_LIBDIR}/version.h

BUILDLINK_TARGETS+=	ruby-base-buildlink

ruby-base-buildlink: _BUILDLINK_USE

.endif	# RUBY_BASE_BUILDLINK2_MK
