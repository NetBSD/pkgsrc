dnl $NetBSD: configure.ac,v 1.1.1.1 2004/02/21 23:03:02 jmmv Exp $

dnl -----------------------------------------------------------------------

dnl Check for host details.
AC_CANONICAL_HOST

dnl -----------------------------------------------------------------------

dnl Check for compilers and preprocessors.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_CXXCPP

dnl -----------------------------------------------------------------------

dnl Check for libtool and the maximum command line length supported by the
dnl system, as this takes a long time.
AM_PROG_LIBTOOL
AC_LIBTOOL_SYS_MAX_CMD_LEN

dnl -----------------------------------------------------------------------

dnl Check for compiler features.
AC_C_BACKSLASH_A
AC_C_BIGENDIAN
AC_C_CONST
AC_C_RESTRICT
AC_C_VOLATILE
AC_C_INLINE
AC_C_CHAR_UNSIGNED
AC_C_LONG_DOUBLE
AC_C_STRINGIZE
AC_C_PROTOTYPES
AC_PROG_CC_C_O
AC_PROG_GCC_TRADITIONAL

dnl -----------------------------------------------------------------------

dnl Check for standard header files.
AC_HEADER_DIRENT
AC_HEADER_MAJOR
AC_HEADER_STAT
AC_HEADER_STDBOOL
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_HEADER_TIME
AC_HEADER_TIOCGWINSZ
AC_CHECK_HEADERS([sys/cdefs.h \
                  sys/ioctl.h \
                  sys/mount.h \
                  sys/param.h \
                  sys/resource.h \
                  sys/stat.h \
                  sys/statvfs.h \
                  sys/sysctl.h \
                  sys/types.h \
                  sys/utsname.h \
                  sys/varargs.h \
                  sys/vfs.h \
                  argz.h \
                  assert.h \
                  ctype.h \
                  err.h \
                  fcntl.h \
                  fstab.h \
                  inttypes.h \
                  libgen.h \
                  limits.h \
                  malloc.h \
                  mntent.h \
                  mount.h \
                  paths.h \
                  signal.h \
                  stdarg.h \
                  stddef.h \
                  stdint.h \
                  strings.h \
                  util.h \
                  varargs.h \
                  wctype.h],,,
                 [[#if HAVE_SYS_CDEFS_H
                   # include <sys/cdefs.h>
                   #endif
                   #if HAVE_SYS_PARAM_H
                   # include <sys/param.h>
                   #endif]])
AC_LANG_PUSH(C++)
AC_CHECK_HEADERS([bitset \
                  deque \
                  fstream \
                  iostream \
                  list \
                  map \
                  queue \
                  set \
                  stack \
                  string \
                  vector])
AC_LANG_POP(C++)

dnl -----------------------------------------------------------------------

dnl Check for standard functions.
AC_FUNC_ALLOCA
AC_FUNC_CHOWN
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FNMATCH
AC_FUNC_FORK
AC_FUNC_FSEEKO
AC_FUNC_GETGROUPS
AC_FUNC_GETMNTENT
AC_FUNC_GETPGRP
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_MBRTOWC
AC_FUNC_MKTIME
AC_FUNC_MMAP
AC_FUNC_OBSTACK
AC_FUNC_REALLOC
AC_FUNC_SELECT_ARGTYPES
AC_FUNC_SETPGRP
AC_FUNC_STAT
AC_FUNC_LSTAT
AC_FUNC_SETVBUF_REVERSED
AC_FUNC_STRCOLL
AC_FUNC_STRTOD
AC_FUNC_STRERROR_R
AC_FUNC_STRFTIME
AC_FUNC_STRNLEN
AC_FUNC_UTIME_NULL
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([__argz_count \
                __argz_next \
                __argz_stringify \
                __fsetlocking \
                basename \
                bzero \
                connect \
                dirname \
                dup2 \
                err \
                errx \
                feof_unlocked \
                fgets_unlocked \
                getc_unlocked \
                getcwd \
                getdelim \
                getdtablesize \
                getegid \
                geteuid \
                getgid \
                gethostbyname \
                getmode \
                getprogname \
                gettimeofday \
                getuid \
                inet_pton \
                lockf \
                lseek64 \
                memchr \
                memcpy \
                memmove \
                memset \
                mempcpy \
                mmap \
                mkdir \
                mkfifo \
                mkstemp \
                mkstemps \
                mktemp \
                munmap \
                open64 \
                poll \
                putenv \
                readdir_r \
                remove \
                setegid \
                setenv \
                seteuid \
                setmode \
                setprogname \
                setresgid \
                setresuid \
                shmat \
                sigaction \
                sigset \
                snprintf \
                socket \
                statvfs \
                stpcpy \
                strcasecmp \
                strchr \
                strrchr \
                strdup \
                strerror \
                stricmp \
                strlcat \
                strlcpy \
                strncasecmp \
                strncat \
                strncpy \
                strndup \
                strspn \
                strstr \
                strtoul \
                tsearch \
                uname \
                vasprintf \
                vsnprintf \
                waitpid \
                wait3 \
                warn \
                warnx])

dnl -----------------------------------------------------------------------

dnl Check for standard types.
AC_CHECK_TYPES([gid_t,
                int16_t,
                int32_t,
                int64_t,
                int8_t,
                mode_t,
                off_t,
                ptrdiff_t,
                rlim_t,
                sig_t,
                size_t,
                ssize_t,
                u_int16_t,
                u_int32_t,
                u_int64_t,
                u_int8_t,
                uid_t,
                uint16_t,
                uint32_t,
                uint64_t,
                uint8_t])

dnl -----------------------------------------------------------------------

dnl Check for standard sizes.
AC_CHECK_SIZEOF(char)
AC_CHECK_SIZEOF(short)
AC_CHECK_SIZEOF(int)
AC_CHECK_SIZEOF(long)
AC_CHECK_SIZEOF(long long)

dnl vim: syntax=config:expandtab:shiftwidth=4:softtabstop=4
