# $NetBSD: buildlink2.mk,v 1.1 2002/10/09 17:17:13 wiz Exp $
#

.if !defined(RUBY_BASE_BUILDLINK2_MK)
RUBY_BASE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ruby-base
BUILDLINK_DEPENDS.ruby-base?=		ruby-base>=1.6.7nb3
BUILDLINK_PKGSRCDIR.ruby-base?=		../../lang/ruby-base
EVAL_PREFIX+=	BUILDLINK_PREFIX.ruby-base=ruby-base
BUILDLINK_PREFIX.ruby-base_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ruby-base=	lib/libruby.*
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/config.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/curses.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/dbm.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/defines.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/dln.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/env.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/etc.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/fcntl.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/intern.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/libruby.a
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/nkf.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/node.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/pty.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/rbconfig.rb
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/re.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/regex.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/ruby.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/rubyio.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/rubysig.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/sdbm.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/socket.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/st.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/syslog.so
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/util.h
BUILDLINK_FILES.ruby-base+=	lib/ruby/1.6/i386-netbsdelf/version.h

BUILDLINK_TARGETS+=	ruby-base-buildlink

ruby-base-buildlink: _BUILDLINK_USE

.endif	# RUBY_BASE_BUILDLINK2_MK
