The builtin SQLite3 in NetBSD lacks features needed by Synapse.  In
addition, the version in NetBSD 9 is too old.  To use Synapse with
SQLite3, one must build with pkgsrc sqlite3, via
PREFER_PKGSRC+=sqlite3.
